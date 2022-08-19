function Game(side, time) { // 게임
	let cardsArray = twoDArray(side, side);
	let ans;
	
	initializeCards(cardsArray);
  displayFullCards(side, cardsArray);
	
	while(ans == side * side / 2) {
		// let row1 = 
		// let col1 = 
		// let row2 = 
		// let col2 = 
		// 선택된 요소의 배열 row col 값을 저장
		// ans를 크게 해서 무한 루프에 빠지지 않도록 처리
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

function checkAns (array, row1, col1, row2, col2) {
  side = Math.sqrt(array.length);
	if(array[row1 * side + col1] == array[row2 * side + col2]) {
		// document의 클릭된 노드를 가져와서 삭제 시킨다.
	} else {
		// 선택된 항목을 다시 뒤집는 함수
	}
}

// ** 참고 **
// 화면 띄우는 함수들 시작

function addCard(number) {	// 카드 객체를 만드는 함수 : number가 적혀있는 카드 DOM을 배출
  let cardBorder = document.createElement("div");
  let className = document.createAttribute("class");
  className.value = "card";
  cardBorder.setAttributeNode(className);
  
  let cardValue = document.createTextNode(number);
  cardBorder.appendChild(cardValue);
  
  cardBorder.addEventListener('click', function() {console.log("Hi")})
  
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


function flipCard() {
  
}


Game(6, 1);
