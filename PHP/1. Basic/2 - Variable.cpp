<?php
$x = 5;
$y = 4;
echo "1st element ".$x. "\n";
echo "2nd element ".$y. "\n";
echo $x + $y;
?>
 

<?php
$txt = "W3Schools.com";
echo "I love ".$txt;
?>


<?php
 echo "Please enter value 1 : ";
 fscanf(STDIN, "%d\n", $value1); // reads number from STDIN standard input
 echo "Please enter value 2 : ";
 fscanf(STDIN, "%d\n", $value2);
 echo "Answer : " .($value1 + $value2) . "\n";
?>

 
 
 
//Local Variable 
<?php
function myTest() 
{
    $x = 5; // local scope
    echo "Variable x inside function is: $x"."\n";
} 

myTest();

echo "Variable x outside function is: $x";
?>
       

//Global Variable
<?php
$x = 5;
$y = 10;
$z;

function myTest() 
{
    global $x, $y, $z;
    $z = $x + $y;
}

myTest();
echo $z; // outputs 15
?>
 
 
 
 //Static Variable
 <?php
function myTest() {
    static $x = 0;
    echo $x;
    $x++;
}

myTest();
myTest();
myTest();
?>
 
 
 
 
 
 
 
 
 
