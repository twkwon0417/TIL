let clickedArray = new Array();
let ans = 0;
function Game(side, time) { // 게임
	let cardsArray = twoDArray(side, side);
	
	initializeCards(cardsArray);
  displayFullCards(side, cardsArray);
	while(true) {
    if(ans == side * side / 2) {
      console.log("done");
      break;
    }
  }
	// 성공! 띄우던가 말던가
}

function twoDArray(row, col) { //JS는 이차원 객체를 한번에 만들수 없어서 만든 함수
	let output = new Array(row * col);
	
	return output;
}

function shuffleArray(array) {
  array.sort(() => Math.random() - 0.5);
}

function initializeCards(array) { // 게임 시스템 함수로써 가상 카드(배열)
	let numOfCards = array.length;
	let assign = 1;
	
	for(let i = 0; i < numOfCards; i += 2) {
    console.log(i);
		array[i] = assign;
		array[i + 1] = assign;
    assign++;
	}
	
	shuffleArray(array);
  console.log(array);
}

function checkAns () {
  if(clickedArray[0] == clickedArray[1]) {
    ans++
    let cardClass = clickedArray[0];
    let toBeDeleted = document.getElementsByClassName(cardClass);
    for(let i = 0; i < 2; i++) {
      toBeDeleted[i].style.visibility = "hidden";
      clickedArray.pop();
    }
    
  } else {
    // 그냥 다시 뒤집기
  }  
}

// ** 참고 **
// 화면 띄우는 함수들 시작

function addCard(number) {	// 카드 객체를 만드는 함수 : number가 적혀있는 카드 DOM을 배출
  let cardBorder = document.createElement("div");
  let className = document.createAttribute("class");
  className.value = number;
  cardBorder.setAttributeNode(className);
  
  cardBorder.style.backgroundColor = "blue";
  cardBorder.style.width = "20px";
  cardBorder.style.height = "30px";
  cardBorder.style.color = "red";
  cardBorder.style.textAlign = "center";
  cardBorder.style.lineHeight = "30px";
  cardBorder.style.margin = "2px";
  cardBorder.style.display = "inline-block";
  cardBorder.style.position = "reative";
  cardBorder.style.borderStyle = "solid";
  cardBorder.style.borderColor = "green";
  
  let cardValue = document.createTextNode(number);
  cardBorder.appendChild(cardValue);
  
  cardBorder.addEventListener('click', function() {
    clickedArray.push(number);
    if(clickedArray.length == 2) {
      checkAns();
    }
  })  // flipCard()는 화면에 띄워지는게 아님
  
  return cardBorder;
}

function displayColCard(card) { // 화면에 띄울 카드배열의 행을 담당
	document.getElementsByTagName("body")[0].appendChild(card);
}

function displayRowCard() { // 화면에 띄울 카드배열의 렬을 담당
	let div = document.createElement("div");
	div.style.height = "1px";
	document.getElementsByTagName("body")[0].appendChild(div);
}

function displayFullCards(side, assignTable) { // 위 두 함수를 이용해서 카드배열을 직접적으로 띄우는 함수
	for(let i = 0; i < side; i++) {
		for(let j = 0; j < side; j++) {
			let thing = addCard(assignTable[i * side + j]);
			displayColCard(thing);
		}
		displayRowCard();
	}
}


Game(2, 1);
