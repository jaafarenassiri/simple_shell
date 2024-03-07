const express=require('express');
const router=express.Router();
const {blogs}=require('../models');
const multer = require('multer');
const fs = require('fs');
const path = require('path');// Added missing import
const { validerToken } = require('../middleware/auth');

const storage = multer.diskStorage({
    destination: 'uploads/',
    filename: (req, file, cb) => {
      cb(null, file.originalname);
    }
  });
  const upload = multer({ storage: storage });

  router.get('/', async (req, res) => {
    const listBlogs = await blogs.findAll();
    res.json(listBlogs);
  });

  router.get('/:id', async (req, res) => {
    const blog = await blogs.findByPk(req.params.id);
    res.json(blog);
  });
  
  router.post('/', validerToken, upload.array('photo'), async (req, res) => {
    console.log('succ');
    const { text, title } = req.body;
    let photoPath = '';
    for(let i=0;i<req.files.length;i++){
      photoPath+=req.files[i].filename;
    }
    await blogs.create({
      text:text,
      title:title,
      image: photoPath,
    });
    res.json('succ');
  });
  
  router.post('/update/:id', validerToken,upload.array('photo'), async (req, res) => {
        const Blog=await blogs.findByPk(req.params.id);
        console.log(req.body)
       const {title,text}=req.body;
        Blog.title=title;
        Blog.text=text;
        await Blog.save();
  });
  
  router.delete('/:id', validerToken, async (req, res) => {
    const Blog = await blogs.findByPk(req.params.id);
    if (!Blog) {
      console.log('Article not found');
    } else {
      const imagePath = Blog.image;
      console.log(imagePath);
  
      await blogs.destroy({ where: { id: req.params.id } });
    
      fs.unlink("./uploads/"+imagePath, (err) => {
        if (err) {
          console.log(err);
          console.log('sasa');
        } else {
          console.log('Successfully deleted image file');
        }
      })
    }})
module.exports=router;