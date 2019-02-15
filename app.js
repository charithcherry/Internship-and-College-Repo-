/**
 * INSTRUCTIONS:
 * open the terminal ( CTRL + ~ ) in visual studio code
 * 
 * type the below command in the terminal
 * npm start
 * 
 * You must see nodemon running in the terminal
 * 
 * If you open browser and navigate to localhost:3000
 * You must see the response
 * 
 * Hurray! You're ready!
 */

const express = require('express')

const app = express()

app.use((req, res, next) => {
    console.log('Hurray working!')
    res.send('<h1>You are now looking at the response</h1>')
})

app.listen(3000)
