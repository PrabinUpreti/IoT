function initApp() {
  // var xhttp = new XMLHttpRequest();
  // xhttp.onreadystatechange = function() {
  //   if (this.readyState == 4 && this.status == 200) {
  //     // console.log(this.responseText);
  //   }
  // };
  // xhttp.open("GET", "../server/server.php", true);
  // xhttp.send();
}
function sendRequest(id) {
  // var res;
  // var paramg;
  document.getElementById(id).classList.remove('btn-primary');
  document.getElementById(id).classList.add('btn-warning');
  document.getElementsByClassName("get_id")[0].disabled = true;
  document.getElementsByClassName("get_id")[1].disabled = true;
  document.getElementsByClassName("get_id")[2].disabled = true;
  document.getElementsByClassName("get_id")[3].disabled = true;
  var xhttp = new XMLHttpRequest();
    //   if(this.readyState == 0){
    //     console.log("0: request not initialized");
    //   }
    //   if(this.readyState == 1){
    //     console.log("1: server connection established");  
    //   }
    //   if(this.readyState == 2){
    //     console.log("2: request received");  
    //   }
    //   if(this.readyState == 3){
    //     console.log("3: processing request");  
    //   }
    //   if(this.readyState == 4){
    //     console.log("4: request finished and response is ready");  
    //   }
    // res = this.responseText;
    // if (this.readyStatus == 4) {
    //   alert(res);
    // }
  // }

  xhttp.open("GET", "http://192.168.254.61:80?pin=" + id, true);
 // xhttp.setRequestHeader("Access-Control-Allow-Headers","http://127.0.0.1:5500");
  // xhttp.setRequestHeader("Origin", "*");
  //xhttp.setRequestHeader("Access-Control-Allow-Methods", "GET, POST,PUT");
  //xhttp.setRequestHeader('Access-Control-Allow-Credential','false');  
    xhttp.send();
  // alert('Sending Request to server!!');
  setTimeout(function(){
    document.getElementById(id).classList.remove('btn-warning');
    document.getElementById(id).classList.add('btn-primary');
    document.getElementsByClassName("get_id")[0].disabled = false;
    document.getElementsByClassName("get_id")[1].disabled = false;
    document.getElementsByClassName("get_id")[2].disabled = false;
    document.getElementsByClassName("get_id")[3].disabled = false;
    if (id % 2 == 0) {
      document.getElementById(id).id = parseInt(id) + 1;
    }
    if (id % 2 != 0) {
      document.getElementById(id).id = parseInt(id) - 1;
    }

  },4000);
  return;

}
// function sendToArduino(id) {

//     var xhttp = new XMLHttpRequest()
//     xhttp.open("GET", "http://10.10.5.101:80/?pin=" + id, false);
//     xhttp.send();
// }
