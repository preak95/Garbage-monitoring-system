This project implements the following in the following ways.
Server:
  Node.js - Asynshronous server
  Express to handel the 2 request:
    1. Request from browser to render the ejs template and sent it to browser.
    2. Request from ESP8266 to receive level data from it.
    3. EJS to render the template with the level data reveived from ESP8266
