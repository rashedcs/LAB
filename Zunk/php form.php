<?php include 'home.php'; ?>
<?php include 'database.php'; ?>


<?php
   $db = new database();

   if(isset($_POST['submit']))
   {

       $roll = mysqli_real_escape_string($db->link, $_POST['roll']);
       $roll = htmlspecialchars($roll);


       $name = mysqli_real_escape_string($db->link, $_POST['name']);
       $name = htmlspecialchars($name);


       $dept = mysqli_real_escape_string($db->link, $_POST['dept']);
       $dept = htmlspecialchars($dept);


       $session = mysqli_real_escape_string($db->link, $_POST['session']);
       $session = htmlspecialchars($session);


 
       $query = " SELECT * from student WHERE roll='$roll' ";
       $result = $db->select($query);

       /*
       if(!filter_var($email,FILTER_VALIDATE_EMAIL) ) 
       { 
           $emailError = "Please enter valid email address.";
           echo $emailError;
       } 
       */
       if($result!=false)
       {
           $user_data = mysqli_fetch_array($result);
           $count_row =  mysqli_num_rows($result); //cou

           if( $count_row==1)
           {
              $emailError = "Roll is taken";
              echo $emailError;
           }
       }
       else
       {
           printf("Registrtion Successful");
           $query="INSERT INTO student(roll, name, dept, session) 
           VALUES('$roll', '$name', '$dept', '$session')";
           $result = $db->insert($query);
       }      

  }
?>


<!DOCTYPE html>
<head>
<meta charset="utf-8">
<title>Sign Up</title>
<style>
form 
{
    border: 3px solid #f1f1f1;
}
h2
{
    text-align: center;
    color: green;
}

input[type=text], input[type=password] 
{
    width: 100%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
}

button 
{
    background-color: #4CAF50;
    color: white;
    padding: 14px 20px;
    margin: 8px 0;
    border: none;
    cursor: pointer;
    width: 100%;
}

button:hover 
{
    opacity: 0.8;
    background-color: red;
}

.container 
{
    /* padding: 10px 100px 100px 100px;   
    padding-top: 10px;
    padding-right: 100px;
    padding-bottom: 100px;
    padding-left: 100px;
    */
   
}

</style>
</head>

<body>
  <h2>Add new Student</h2>
  <form action="registration.php" method="POST">
    <div class="container" >
      <label><b>Roll</b></label>
      <input type="text"   placeholder="Roll" required="1" name="roll" />

      <label><b>Name</b></label>
      <input type="text"   placeholder="Name" required="1" name="name" />

      <label><br>Depertment </br></label>
        <select name="dept" class="form-control" id="default" required="required">
            <option value="">Select Class</option>
            <option value="Plane">Plane</option>
            <option value="Train">Train</option>
            <option value="Own Vehicle">Own Vehicle</option>
            <option value="Other">Other</option>
        </select>
    
      <label><br>Session</br></label>
            <select name="session" class="form-control" id="default" required="required">
            <option value="">2011-12</option>
            <option value="Plane">2012-13</option>
            <option value="Train">2013-14</option>
            <option value="Own Vehicle">2014-15</option>
            <option value="Other">Other</option>
        </select>

     <div>
       <button name="submit" type="submit">Submit</button>
     </div>
  <div>
</form>
</body>
</html>
