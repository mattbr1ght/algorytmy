<?php
$a = readline("Podaj liczbę do obliczenia pierwiastka : ");
if (!is_numeric($a)) { //wcześniej !ctype_digit($a)
  echo "Nie podano poprawnej liczby";
  exit(0);
}
if ($a <= 0) {
  echo "Podana liczba musi być liczbą dodatnią";
  exit(0);
}

function sqrt_iterative($a)
{
  $buffer = -1;
  $i = 1;
  $last_x = $a;
  $continue = null;
  $max_k = 100;
  while ($buffer != $last_x || ($i <= $max_k and $continue == true) || is_null($continue)) {
    if(is_null($continue)){
      $read = readline("Czy kontynuować liczenie pomimo powtarzalności ostatnich wyników (y/n)? : ");
      $continue = ($read == "y" ? true : ($read == "n" ? false : null));
      continue;
    }
    echo $i++ . ". " . $last_x . " \n";
    $buffer = $last_x;
    $last_x = (1 / 2) * ($last_x + ($a / $last_x));
  }
  return $last_x;
}
function sqrt_recursive($a, $k = 0)
{
  if ($k < 0 || $a <= 0) {
    return false;
  }
  if ($k == 0) {
    return $a;
  }
  $res = sqrt_recursive($a, $k-1);
  return (1 / 2) * ($res + ($a / $res));
}

//echo "\npierwiastek z $a wynosi : " . sqrt_iterative($a);
echo "\npierwiastek z $a wynosi : " . sqrt_recursive($a, 100);
