<?php
$a = readline("Podaj liczbę do obliczenia pierwiastka : ");
if(!ctype_digit($a)){
  echo "Nie podano poprawnej liczby";
  exit(0);
}
if($a < 1){
  echo "Podana liczba musi być liczbą dodatnią";
  exit(0);
}
$buffer = -1;
$last_x = $a;
while($buffer != $last_x){
//  echo $last_x . " ";
  $buffer = $last_x;
  $last_x = (1/2) *($last_x + ($a/$last_x));
}
echo "\npierwiastek z $a wynosi : ". $last_x;
