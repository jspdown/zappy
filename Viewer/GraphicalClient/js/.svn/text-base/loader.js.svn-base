

//////////////////////////////
//	Loader
/////////////////////////////
var percent = {
	tiles:	40,
	ressources:	20,
	assets:	40,
};

var finish_foo = null;

function	Loader() {
	this.percentage = 0;
}

Loader.prototype.incress = function (nbr) {
	this.percentage += nbr;
	document.getElementsByClassName("bar")[0].style.width = this.percentage + "%";
}

Loader.prototype.addStep = function	(name) {
	var ul = document.getElementsByTagName('ul')[0];
	var li = document.createElement('li');
	var txt = document.createTextNode(name);
	li.appendChild(txt);
	ul.appendChild(li);
}

Loader.prototype.addAlert = function (msg) {
	document.getElementById("alerts").innerHTML = '<div class="alert alert-error">' + msg + '</div>';
}

Loader.prototype.clear = function () {
	document.getElementById("loader").innerHTML = "";
}

//////////////////////////////
// Connect
//////////////////////////////


var connected_content = '\
		<div id="loader">\
			<div class="progress progress-striped active">\
				<div class="bar" style="width: 10%;"></div>\
			</div>\
			<div class="hero-unit">\
				<ul>\
				</ul>\
			</div>\
			<div id="alerts">\
			</div>\
		</div>\
		<div id="container">\
		</div>';
	
var connect_content = '\
<div class="hero-unit">\
	<form action="#" class="form-horizontal" onSubmit="spy();return false">\
	  <div class="control-group">\
	    <label class="control-label" for="host">Host</label>\
	    <div class="controls">\
	      <input type="text" id="host" placeholder="127.0.0.1">\
	    </div>\
	  </div>\
	  <div class="control-group">\
	    <label class="control-label" for="port">Port</label>\
	    <div class="controls">\
	      <input type="text" id="port" placeholder="4141">\
	    </div>\
	  </div>\
	  <div class="control-group">\
	    <div class="controls">\
	      <button type="submit" class="btn">Spy</button>\
	    </div>\
	  </div>\
	 </form>\
</div>\
'
	
function	showConnect() {
	document.getElementById("main").innerHTML = connect_content;
}
function	spy() {
	var host = document.getElementById("host").value;
	var port = parseInt(document.getElementById("port").value, 10);
	document.getElementById("main").innerHTML = connected_content;
	if (port > 0 && port < 44405 && host.length > 0) {
		newGame(host + ":" + port);
	}
	return (false);
}

showConnect();