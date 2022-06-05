function refreshTime() {
  var dateString = new Date().toLocaleString("pt-PT", {
    timeZone: "Europe/Lisbon",
  });
  var formattedString = dateString.replace(", ", " - ");
  document.getElementById("time").innerHTML = formattedString;
}

setInterval(refreshTime, 1000);

function renderLeic(message) {
  secretaria = JSON.parse(message);
  let template = '';
  let template5 = '';

  for (var i = 0; i < 5; i++) {
    if (secretaria.leic[i].mesa == "5") {
      template5 += `
            <div class="mesa_5">
                <div class="text">
                    <h2 class="mesa_titulo"> Mesa ${secretaria.leic[i].mesa} </h2>
                    <h4 class="name"> ${secretaria.leic[i].name} </h4>
                </div>
            `;
      if (secretaria.leic[i].sensor == "Livre") {
        template5 += `
                <p class="estado_green"> ${secretaria.leic[i].sensor} </p>
            </div>
            `;
      } else {
        template5 += `
                <p class="estado_red"> ${secretaria.leic[i].sensor} </p>
            </div>
            `;
      }
    } else {
      template += `
            <div class="mesa">
                <div class="text">
                    <h2 class="mesa_titulo"> Mesa ${secretaria.leic[i].mesa} </h2>
                    <h4 class="name"> ${secretaria.leic[i].name} </h4>
                </div>
            `;
      if (secretaria.leic[i].sensor == "Livre") {
        template += `
                <p class="estado_green"> ${secretaria.leic[i].sensor} </p>
            </div>
            `;
      } else {
        template += `
                <p class="estado_red"> ${secretaria.leic[i].sensor} </p>
            </div>
            `;
      }
    }
  }
  document.getElementById("test_4").innerHTML = template;
  document.getElementById("test_5").innerHTML = template5;
}
