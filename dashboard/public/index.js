var index = 0;

const renderLeic = async () =>{
    let uri='http://localhost:3000/leic';

    const res = await fetch(uri);
    const leic = await res.json();

    console.log(leic);

    let template = '';
    let template5 = '';
    
    leic.forEach(leic => {
        if(leic.mesa == "5") {
            template5 += `
            <div class="mesa_5">
                <div class="text">
                    <h2 class="mesa_titulo"> Mesa ${leic.mesa} </h2>
                    <h4 class="name"> ${leic.name} </h4>
                </div>
            `
            if(leic.sensor == "Livre") {
                template5 += `
                <p class="estado_green"> ${leic.sensor} </p>
            </div>
            `
            } else {
                template5 += `
                <p class="estado_red"> ${leic.sensor} </p>
            </div>
            `
            }
        } else {
            template += `
            <div class="mesa">
                <div class="text">
                    <h2 class="mesa_titulo"> Mesa ${leic.mesa} </h2>
                    <h4 class="name"> ${leic.name} </h4>
                </div>
            `
            if(leic.sensor == "Livre") {
                template += `
                <p class="estado_green"> ${leic.sensor} </p>
            </div>
            `
            } else {
                template += `
                <p class="estado_red"> ${leic.sensor} </p>
            </div>
            `
            }
        }
    })
    document.getElementById("test_4").innerHTML = template;
    document.getElementById("test_5").innerHTML = template5;
}

window.addEventListener ('DOMContentLoaded', renderLeic());