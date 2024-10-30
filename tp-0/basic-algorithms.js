function findMax(numbers) {
  let max = numbers[0]; 

  for (let i = 1; i < numbers.length; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }

  return max;
}

const numbers = [3, 5, 1, 9, 2];
console.log(findMax(numbers));

function factorial(n) {
  let result = 1;
  for (let i = n; i > 1; i--) {
    result *= i;
  }
  return result;
}

console.log(factorial(5));

function reverseArray(arr) {
  let left = 0;
  let right = arr.length - 1;

  while (left < right) {
    [arr[left], arr[right]] = [arr[right], arr[left]];
    left++;
    right--;
  }
  return arr;
}

const charArray = ['H', 'e', 'l', 'l', 'o'];
console.log(reverseArray(charArray));

