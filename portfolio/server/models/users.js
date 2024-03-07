const {Sequelize,DataTypes}=require("sequelize");
module.exports=(Sequelize,DataTypes)=>{
const users=Sequelize.define("users",{
    email:{
    type:DataTypes.STRING,
    allowNull:false,
    },
    password:{
     type:DataTypes.STRING,
     allowNull:false,
    }

   
    
})
return users;
}