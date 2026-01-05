alert("Let's play tic tac toe");

const boxs = document.querySelectorAll(".box");
const statusText = document.querySelector("#status");
const reset = document.querySelector("#reset");

const wincondition = [
  [0,1,2],[3,4,5],[6,7,8],
  [0,4,8],[2,4,6],
  [0,3,6],[1,4,7],[2,5,8]
];

let option = ["","","","","","","","",""];
let currentPlayer = "X";
let running = false;

initialiseGame();

function initialiseGame(){
  boxs.forEach(cell => cell.addEventListener("click", boxClicked));
  reset.addEventListener("click", restartGame);
  statusText.textContent = `${currentPlayer}'s turn`;
  running = true;
}

function boxClicked(){
  const dataindex = this.getAttribute("data-index");

  if(option[dataindex] !== "" || !running){
    return;
  }

  updatedBox(this, dataindex);
  checkWinner();
}

function updatedBox(box, index){
  option[index] = currentPlayer;
  box.textContent = currentPlayer;
}

function changePlayer(){
  currentPlayer = (currentPlayer === "X") ? "O" : "X";
  statusText.textContent = `${currentPlayer}'s turn`;
}

function checkWinner(){
  let roundWon = false;

  for (let i = 0; i < wincondition.length; i++) {
    const condition = wincondition[i];
    const a = option[condition[0]];
    const b = option[condition[1]];
    const c = option[condition[2]];

    if (a === "" || b === "" || c === "") {
      continue;
    }

    if (a === b && b === c) {
      roundWon = true;
      break;
    }
  }

  if (roundWon) {
    statusText.textContent = ` Player ${currentPlayer} wins!`;
    running = false;
  }
  else if (!option.includes("")) {
    statusText.textContent = "🤝 It's a draw!";
    running = false;
  }
  else {
    changePlayer();
  }
}

function restartGame(){
  currentPlayer = "X";
  option = ["","","","","","","","",""];
  statusText.textContent = `${currentPlayer}'s turn`;
  running = true;

  boxs.forEach(box => box.textContent = "");
}
