window.onload = function(){
	var testdiv = document.getElementById('testdiv');
	testdiv.innerHTML = "<p>inserted text.</p>";
	alert(testdiv.firstChild.firstChild.nodeValue);
}