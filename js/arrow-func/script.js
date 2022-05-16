const todos = [

    {title:"Основи JavaScript", completed: true},
    
    {title:"Arrow (стрілочні) ф-ції", completed: false},
    
    {title:"Анонімні ф-ції", completed: false},
    
    ];
    
    
    
    // Array.prototype.filter – https://developer.mozilla.org/ru/docs/Web/JavaScript/Reference/Global_Objects/Array/filter
    
const incompleted = todos.filter(item => !item.completed);