<?php
 echo "Please enter value 1 : ";
 fscanf(STDIN, "%d\n", $value1); // reads number from STDIN standard input
 echo "Please enter value 2 : ";
 fscanf(STDIN, "%d\n", $value2);
 echo "Answer : " .($value1 + $value2) . "\n";
?>
