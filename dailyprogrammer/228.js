const stopWords = "I a about an are as at be by com for from how in is it of on or that the this to was what when where who will with the".split(' ');

const input = `The daily diary of the American dream
For the sky and the sea, and the sea and the sky
Three grey geese in a green field grazing, Grey were the geese and green was the grazing.
But a better butter makes a batter better.
"His soul swooned slowly as he heard the snow falling faintly through the universe and faintly falling, like the descent of their last end, upon all the living and the dead."
Whisper words of wisdom, let it be.
They paved paradise and put up a parking lot.
So what we gonna have, dessert or disaster?`;

const frequencies = input
.split('\n')
.map(line => {
  line
  .split(' ');
  .map(word => {
    return word[0];
  })
  .reduce((prev, cur) => {
    if (prev.hasOwnProperty(cur)) {
      prev[cur]++;
    }
    else {
      prev[cur] = 0;
    }
  }, {})
  .keys()

});


