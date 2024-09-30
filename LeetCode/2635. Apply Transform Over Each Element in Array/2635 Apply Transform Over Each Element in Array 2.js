var map = function(arr, fn) {
    let narr = []
    for(let i=0;i<arr.length;i++)
    {
        narr.push(fn(arr[i],i))
    }
    return narr
};
