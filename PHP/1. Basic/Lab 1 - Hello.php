<!DOCTYPE html>
<html>
<body>

<?php
echo "I Love PHP!";
?> 

</body>
</html>



//Input From User
<?php
echo "Enter your name\n"; // Output - prompt user
$name = fgets(STDIN);     // Read the input
echo "Hello $name";       // Output - Some text   
exit(0);                  // Script ran OK
?>
