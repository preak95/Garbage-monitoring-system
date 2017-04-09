
function setup() {
    "use strict";
    background(0);
    createCanvas(600, 400);
}


function paintInnerRect(r, H){
    "use strict";
    function draw(){
        fill(1,1,1);
        rect(200, 200, 120, 180);
        fill(150, 150, 150);
        rect(r.x, r.y, r.w, H);
    }
}
console.log('Sketch running!');