const {verify}=require('jsonwebtoken');
const validerToken=(req,res,next)=>{
const accesstoken=req.header("accesstoken");
if(!accesstoken){res.json({error:"you are not logged in",why:`${accesstoken}`})};
    try{
        const validToken = verify(accesstoken, 'hahahaha');
        req.user=validToken;

        if(validToken){
          return next();
        }
        } catch(err){
        return console.log('problem');
        }
        }
module.exports={validerToken};
