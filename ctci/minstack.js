const Minheap = {
  data: [],
  rootIndex: function() { return 0 },
  rootValue: function() { return this.data[0] },
  leftChildLoc: function(i) { return 2*i + 1 },
  rightChildLoc: function(i) { return 2*i + 2 },
  parentLoc: function() { return Math.floor((i-1)/2) },
  addNode: function(val) {
    console.log(this);
  }
};

Minheap.addNode();
