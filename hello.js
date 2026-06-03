

function hi(){
    return new Promise((res,rej)=>{
        //setTimeout(()=>{res("result is buhahah")},2000);
        console.log("My name is hemanth kumar ")
        setTimeout(()=>{rej("result is dengeyyi")},2000);
        console.log("My name is hemanth kumar vaddipalli ")
    });
}


hi().then((res)=>{
    console.log(res);
}).catch((rej)=>{
    console.log("I am from catch : ",rej);
})

console.log("I am king of the world");