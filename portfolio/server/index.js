const express=require("express")
const app=express();
const db=require('./models');
var cors=require('cors');
app.use(cors())
app.use(express.json());
const routerUsers=require('./routes/users');
const routerBlogs=require('./routes/blogs');
app.use("/users",routerUsers);
app.use("/blogs",routerBlogs);
db.sequelize.sync().then(()=>{
    var server=app.listen(3001,"127.0.0.1",()=>{
        var port=server.address().port;
        var host=server.address().address;
     console.log("Example app listening at http://%s:%s", host,port) })});