"use strict";

// JS called from the client accepts JSON arguments
function addHtml(args) {
    alert("Called");
    var text = args["text"];
    document.getElementById("main-body").innerHTML += text;
}