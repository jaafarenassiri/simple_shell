const {Sequelize,DataTypes}=require("sequelize");
module.exports=(Sequelize,DataTypes)=>{
const blogs=Sequelize.define("blogs",{
    text:{
    type:DataTypes.STRING,
    allowNull:false,
    },
    image:{
        type:DataTypes.STRING,
        allowNull:false
    },
    title:{
        type:DataTypes.STRING,
        allowNull:false
    }
   
    
})
return blogs;
}