const arr = [3, 4, 5, 6, 7, 1, 2];

function findReset(arr) {
  console.log(arr);
  if (arr.length === 1) return arr[0];
  const mid = Math.floor(arr.length / 2);
  // recurse on lower half - second element to mid inclusive
  if (arr[0] > arr[mid]) return findReset(arr.slice(1, mid+1));
  // recurse on upper half - mid inclusive to end
  else return findReset(arr.slice(mid));
}

findReset(arr);
