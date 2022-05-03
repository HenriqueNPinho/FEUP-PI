var tables=["mesa1", "mesa2", "mesa3", "mesa4", "mesa5"]
var colors=["green", "yellow", "yellow", "green", "red"]

function changeColor(tables, colors) {
    // your code here
    function leftLight() {

      for(let i = 0; i<tables.length;i++){
        var element = document.getElementById(tables[i]);
        element.style.color = colors[i];
      }

    }
    // Also don't forget to call the function
    leftLight();
} 
