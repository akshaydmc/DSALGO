function miracleSqrt(num) {
    while(true) {
        let attempt = Math.floor( Math.random() * num );
        if(attempt ** 2 === num) {
            return attempt;
        }
    }
}

export default miracleSqrt