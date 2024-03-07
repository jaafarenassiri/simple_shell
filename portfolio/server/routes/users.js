const express=require('express');
const router=express.Router();
const {sign}=require('jsonwebtoken');
const bcrypt=require('bcrypt');
const {users}=require('../models');
const { validerToken } = require('../middleware/auth');
router.post('/',async (req,res)=>{
    const {email,password}=req.body;
    const hashedPassword=await bcrypt.hash(password,10);
    
      await users.create({email:email,password:hashedPassword});
      res.json({error:req.body});
    
    })
router.post('/updateAdmin',validerToken,async (req,res)=>{
    const email=req.user.email;
   const  user=await users.findOne({where:{email:email}});
   console.log(req.body);
   if(user){
    if(req.body.emailU&&req.body.passwordU){
    const hashedPassword= await bcrypt.hash(req.body.passwordU,10);
    user.email=req.body.emailU;
   user.password=hashedPassword;
   await user.save();
   res.json('work');
   }else{
    res.json({error:'not work'});
   }
}else{
    res.json({error:'not work'});

}
})
router.post('/login',async (req,res)=>{
    if(req.body.email&&req.body.password){
    const {email,password}=req.body;
    console.log(req.body);
    const user=await users.findOne({where:{email:email}});
    if(user){
        bcrypt.compare(password,user.password).then(match=>{
            if(match){
                const accesstoken=sign({email:email,id:user.id},'hahahaha');
                res.json({token:accesstoken,user:{id:user.id,email:user.email}});
                console.log('work');
            }else{
                res.json({error:'password inncorrect'});
            }
        })
    }else{
        res.json({error:'email does not exist'});
    }
}else{
   res.json({error:'nothing'})
}}
)
router.get('/auth',validerToken,async (req,res)=>{
    const user=await users.findOne({where:{email:req.user.email}});
    if(user){
res.json({token:req.user,user:{id:user.id,email:user.email}})}
    else{
    res.json({error:"you are not log in"});
        }
});
module.exports=router