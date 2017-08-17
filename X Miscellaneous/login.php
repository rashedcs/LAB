<?php 
 include '../lib/Session.php';
 Session::init();
/**   http://www.codingcage.com/2014/12/php-data-insert-and-select-using-oops.html    **/
?>

<?php include '../lib/Database.php'; ?>
<?php include '../lib/Format.php'; ?>



<!DOCTYPE html>
<head>
<meta charset="utf-8">
<title>Login</title>
<link rel="stylesheet" type="text/css" href="css/stylelogin.css"/>
</head>
<body>
<div class="container">
<section id="content">


<?php
 $db = new Database();
 $fm = new Format();

 if($_SERVER['REQUEST_METHOD']=='POST')
 {
    $username = $fm->validation($_POST['username']);
    $password = $fm->validation(md5($_POST['password']));

    $username = mysql_real_escape_string($username);
    $password = mysql_real_escape_string($password);

    $query = "SELECT * FROM tbl_user WHERE user = '$username' AND pass ='$password' " ;
  
    $result = $db->select($query);

    if (!$result) 
    {
          $value = mysql_fetch_array($result); 
          Session::set("login", true);
          Session::set("username",     $value['user']);
          Session::set("userId",           $value['id']);
          header("Location: index.php");
    } 
    else 
    { 
       echo "<span style='color:red;font-size:18px;'> Not Match </span>";
    }
 }
?>

 <form action="login.php" method="post">
  <h1>Admin Login</h1>
  <div>
   <input type="text" placeholder="Username" required="1" 
     name="username" />
  </div>
  <div>
   <input type="password" placeholder="Password" required="1" 
    name="password" />
  </div>
  <div>
   <input type="submit" value="Log in" />
  </div>
 </form><!-- form -->


 <div class="button">
  <a href="http://www.trainingwithliveproject.com" 
  target="_blank">Training with live project</a>
 </div><!-- button -->
 </section><!-- content -->
</div><!-- container -->
</body>
</html>
