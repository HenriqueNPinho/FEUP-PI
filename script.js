

var tables=["mesa1", "mesa2", "mesa3", "mesa4", "mesa5"]
var colors=["green", "yellow", "yellow", "green", "red"]

window.addEventListener("load", function()  {
    // your code here
    readJson()
    function leftLight() {

      for(let i = 0; i<tables.length;i++){
        var element = document.getElementById(tables[i]);
        element.style.color = colors[i];
      }

    }
    // Also don't forget to call the function
    leftLight();
}, false);

function readJson(){
  fetch("./data.json")
.then(response => {
   return response.json();
})
.then(data => console.log(data));
//const json = require('./data.json')
//console.log(json)

}
