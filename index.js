const http = require('http');
const fs = require('fs');
const port = 8000

const express=require('express');
const app=express();
 
//Import PythonShell module.
const {PythonShell} =require('python-shell');
 
//Router to handle the incoming request.
app.get("/", (req, res, next)=>{
    //Here are the option object in which arguments can be passed for the python_test.js.
    let options = {
        mode: 'text',
       // pythonOptions: ['-u'], // get print results in real-time
          scriptPath: './movGenerator.py', //If you are having python_test.py script in same folder, then it's optional.
        //args: ['shubhamk314'] //An argument which can be accessed in the script using sys.argv[1]
    };
     
 
    PythonShell.run('python_test.py',function (err, result){
          if (err) throw err;
          // result is an array consisting of messages collected
          //during execution of script.
          console.log('result: ', result.toString());
        //  res.send(result.toString())
    });
});
 

fs.readFile('./index.html', function (err, html) {
  if (err) {
      throw err; 
  }      
  http.createServer(function(request, response) {  
      response.writeHeader(200, {"Content-Type": "text/html"});  
      response.write(html);  
      response.end();  
  }).listen(8000,() => {console.log(`Server running at http://localhost:${port}/`);  });
});

