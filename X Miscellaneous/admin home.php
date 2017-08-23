<?php include_once "../lib/database.php"; ?>


<!DOCTYPE html>
<head>
<meta charset="utf-8">
<title>Login</title>
<style>

form {
    border: 3px solid #f1f1f1;
}

input[type=text], input[type=password] {
    width: 100%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    box-sizing: border-box;
}

button {
    background-color: #4CAF50;
    color: white;
    padding: 14px 20px;
    margin: 8px 0;
    border: none;
    cursor: pointer;
    width: 100%;
}

button:hover {
    opacity: 0.8;
}

.cancelbtn {
    width: auto;
    padding: 10px 18px;
    background-color: #f44336;
}

.imgcontainer {
    text-align: center;
    margin: 24px 0 12px 0;
}

img.avatar {
    width: 40%;
    border-radius: 50%;
}

.container {
    padding: 200px 600px 600px 400px;
}

span.psw {
    float: right;
    padding-top: 16px;
}

/* Change styles for span and cancel button on extra small screens */
@media screen and (max-width: 300px) {
    span.psw {
       display: block;
       float: none;
    }
    .cancelbtn {
       width: 100%;
    }
}
</style>

</head>
<body>



<?php 
session_start();
$db = new database();

 if($_SERVER['REQUEST_METHOD']=='POST')
 { 
      $username = $_POST['username'];
      $password = $_POST['password'];

     // $query = "SELECT * from tbl_user WHERE username='$username'  and password='$password";

      $query = " SELECT * from tbl_user WHERE username='$username' and password='$password' ";
      
      $result = $db->select($query);
      
      if($result!=false)
      {
           $user_data = mysqli_fetch_array($result);
           $count_row =  mysqli_num_rows($result);

           if ($count_row == 1) 
           {
              $_SESSION['login'] = true; // this login var will use for the session thing
              $_SESSION['id'] = $user_data['id'];
              header("location:index.php");
           }
           else 
           {
            echo 'Wrong username or password';
           }
       }
    }
?>


<form action="login.php" method="post">
  <div class="imgcontainer">
    <img src="img_avatar2.png" alt="Avatar" class="avatar">
  </div>

  <div class="container">
    <label><b>Username</b></label>
    <input type="text" placeholder="Username" required="1" name="username" />

    <label><b>Password</b></label>
    <input type="password" placeholder="Password" required="1" name="password"/>
        
    <button type="submit">Login</button>
    <input type="checkbox" checked="checked"> Remember me
  </div>

</form>

 </div><!-- button -->
 </section><!-- content -->
</div><!-- container -->
</body>
</html>
