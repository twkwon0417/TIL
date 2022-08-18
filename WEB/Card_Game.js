function addCard(number) {
  let cardBorder = document.createElement("div");
  let className = document.createAttribute("class");
  className.value = "card";
  cardBorder.setAttributeNode(className);

  cardBorder.style.backgroundColor = "blue";
  cardBorder.style.width = "20px";
  cardBorder.style.height = "30px";
  cardBorder.style.color = "red";
  cardBorder.style.textAlign = "center";
  cardBorder.style.lineHeight = "30px";
  cardBorder.style.float = "left";
  cardBorder.style.margin = "2px"
  
  let cardValue = document.createTextNode(number);
  cardBorder.appendChild(cardValue);
  
  return cardBorder;
  // document.getElementsByTagName("body")[0].appendChild(cardBorder);
}

let a = addCard(1);
let b = addCard(2);
let c = addCard(3);
document.getElementById("first").appendChild(a);
document.getElementById("first").appendChild(b);
document.getElementById("second").appendChild(c);
// addCard(1);
// addCard(2);
// addCard(3);
// addCard(4);
// addCard(5);

//https://study-zone.tistory.com/14
