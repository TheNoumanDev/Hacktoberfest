const gameoversound=new Audio('gameoversound.mp3');
const movesound=new Audio('movesound.mp3');
const musicsound=new Audio('musicsound.mp3');
const foodsound=new Audio('foodsound.mp3');
let start={x:0,y:0};
let snakea=[{x:10,y:10}];
let food={x:5,y:5};
let last=0;
let score=0;
function main(ctime)
{
    window.requestAnimationFrame(main);
    if((ctime-last)/1000<0.15)
    {return;}
    last=ctime;
    game();
}
function isCollide(snake)
{
    for (let i = 1; i < snakea.length; i++) 
    {
        if(snake[0].x===snake[i].x && snake[0].y===snake[i].y)
        {
            return true;
        }    
    }
    if(snake[0].x>=20 || snake[0].x<=0 || snake[0].y>=20 || snake[0].y<=0)
    {
        return true;
    }
    return false;
}
function game()
{
    if(isCollide(snakea))
    {
        gameoversound.play();
        start={x:0,y:0};
        alert("Life ain't easy...GAME OVER :\")");
        snakea=[{x:10,y:10}];
        score=0;
          
    }
    if(food.x===snakea[0].x && food.y===snakea[0].y)
    {
        foodsound.play();
        musicsound.play();
        score=score+1;
        marks.innerHTML="Score: "+score;
        snakea.unshift({x:snakea[0].x+start.x,y:snakea[0].y+start.y});
        let a =1;
        let b= 19;
        food={x:Math.round(a+(b-a)*Math.random()),y:Math.round(a+(b-a)*Math.random())}
    }
    for(let i=snakea.length-2;i>=0;i--)
    {
        snakea[i+1]={...snakea[i]};
    }
    snakea[0].x=snakea[0].x+start.x;
    snakea[0].y=snakea[0].y+start.y;
    board.innerHTML="";


    for(let i=0;i<snakea.length;i++)
    {
        snakeEl=document.createElement('div');
        snakeEl.style.gridColumnStart=snakea[i].x;
        snakeEl.style.gridRowStart=snakea[i].y;
        if(i===0)
        {
            snakeEl.classList.add('head');
        }
        else
        {
            snakeEl.classList.add('snake');
        }
        board.appendChild(snakeEl);
    };
    foodEl=document.createElement('div');
    foodEl.style.gridRowStart=food.y;
    foodEl.style.gridColumnStart=food.x;
    foodEl.classList.add('food');
    board.appendChild(foodEl);
}


window.requestAnimationFrame(main);

window.addEventListener('keydown',function(event)
{
    start={x:1,y:0}
    movesound.play();
    if (event.keyCode==37) 
    {
       start.x=-1;
       start.y=0;
    }
    else if (event.keyCode==39) 
    {
       start.x=1;
       start.y=-0;
    }
    else if (event.keyCode==38) 
    {
       start.x=0;
       start.y=-1;
    }
    else if (event.keyCode==40) 
    {
       start.x=0;
       start.y=1;
    }

});


