#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, async function (error1, response1, body) {
  if (error1) {
    return console.log(error1);
  } else {
    const characters = JSON.parse(body).characters;
    for (const character in characters) {
      const response2 = await new Promise((resolve, reject) => {
        request(characters[character], (error2, response2, html) => {
          if (error2) {
            reject(error2);
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(response2);
    }
  }
});
