
var cell_size = 90;
let informationArray = [[] ,[] , [], [], [], [], [], [], []];
function setup() {
  let width = 900;
  let height = 900;
  let exportButton = createButton('Export to CSV');
  exportButton.position(50, 100);
  exportButton.mousePressed(exportCSV);
  createCanvas(width, height);
  background(220);
  stroke(245);
  for (i=1; i<9; i++) {
    line(cell_size*(1/2+i), cell_size/2, cell_size*(1/2+i), cell_size*(10-1/2));
    line(cell_size/2, cell_size*(1/2+i), cell_size*(10-1/2), cell_size*(1/2+i));
  }
  stroke(45);
  for (i=0; i<=3; i++) {
    line(cell_size*(1/2+i*3), cell_size/2, cell_size*(1/2+i*3), cell_size*(10-1/2));
    line(cell_size/2, cell_size*(1/2+i*3), cell_size*(10-1/2), cell_size*(1/2+i*3));
  }
  for (i=0; i<9; i++) {
    for(j=0;j<9;j++) {
      informationArray[i][j] = 0;
    }
  }
}
function draw() {
  noStroke();
  if(keyIsPressed) {
    x = round(mouseX/cell_size)-1
    y = round(mouseY/cell_size)-1
    if(x>8 || x<0 || y>8 || y<0) {
      return;
    }
    realKey = String.fromCharCode(keyCode);
    if(keyCode == 46 || keyCode == 8) {
      push();
        fill(220);
        rect(cell_size*(1/2+x)+10, cell_size*(1/2+y)+10, cell_size-20,cell_size-20)
      pop();
      informationArray[y][x] = 0;
    }
    if(Number.isInteger(Number(realKey)) && realKey>0) {
      if(informationArray[y][x]!=0) {
        informationArray[y][x] = 0;
        push();
        fill(220);
        rect(cell_size*(1/2+x)+10, cell_size*(1/2+y)+10, cell_size-20,cell_size-20)
        pop();
      }
      textAlign(CENTER, CENTER);
      textSize(36);
      text(realKey, x*cell_size+cell_size,y*cell_size+cell_size);
      informationArray[y][x] = realKey;
    }
  }
}
function exportCSV() {
  var outFile = "";
  for(i = 0; i < 9; i++){
    for(j=0; j<9; j++) { 
        outFile += informationArray[i][j];
        outFile+=",";
        if (j==2) {
          outFile+=",";
        }
        if (j==5) {
          outFile+=",";
        }
    }
    outFile+="\n";
    if(i==2) {
      outFile+="\n";
    }
    if(i==5) {
      outFile+="\n";
    }
  }
  axios({
    url:'http://127.0.0.1:5500/',
    method:'GET',
    responseType: 'blob'
  })
  .then(() => {
    const url = window.URL
    .createObjectURL(new Blob([outFile]));
            const link = document.createElement('a');
            link.href = url;
            link.setAttribute('download', 'outfile.csv');
            document.body.appendChild(link);
            link.click();
  })
}