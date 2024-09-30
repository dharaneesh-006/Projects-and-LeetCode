
var filter = function(arr, fn) {
   let sam = []
   for (let i = 0;i < arr.length ; i++)
   {
        if(fn(arr[i],i))
        {
            sam.push(arr[i])
        }
   } 
   return sam
};
