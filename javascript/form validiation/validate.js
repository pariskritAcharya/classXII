function validate(){
  
    let password = document.getElementById("password").value;


    if(password.length<8){
        alert("password must be at least 8 characters");
        return false;
    }



}