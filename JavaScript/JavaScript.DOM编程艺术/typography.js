/*显示缩略语列表
1. 遍历所有abbr元素
2. 获取abbr元素的title和text信息
3. 创建一个定义列表（dl元素）
4. 生成定义列表项（dt和dd）
5. 将定义列表添加到文档中
*/
function displayAbbrs(){
	var definelist = document.createElement("dl");
	var abbrs = document.getElementsByTagName("abbr");
	if(abbrs.length > 0){
		for (var i = abbrs.length - 1; i >= 0; i--) {
			//获取缩略语信息
			var abbr_text = abbrs[i].getAttribute("title");
			var abbr_title = abbrs[i].lastChild.nodeValue;
			//创建dt节点
			var dtitle = document.createElement("dt");
			var dtitle_text = document.createTextNode(abbr_title);
			dtitle.appendChild(dtitle_text);
			//创建dd节点
			var ddesc = document.createElement("dd");
			var ddesc_text = document.createTextNode(abbr_text);
			ddesc.appendChild(ddesc_text);
			//将dt，dd节点添加到dl
			definelist.appendChild(dtitle);
			definelist.appendChild(ddesc);
		}
		//创建标题
		var header = document.createElement("h2");
		var header_text = document.createTextNode("abbrs");
		header.appendChild(header_text);
		//将标题和dl添加到文档
		document.getElementsByTagName("body")[0].appendChild(header).appendChild(definelist);
	}
}

/*显示文献链接
1. 获得blockquote里的cite属性
2. 创建文献链接
3. 插入到文档
*/
function displayCitations(){
	//获得bolckquote元素
	var quotelist = document.getElementsByTagName("blockquote");
	for(var i = 0; i < quotelist.length; i++) {
		//有cite属性
		if(quotelist[i].getAttribute("cite")){
			var url = quotelist[i].getAttribute("cite");
			//找到插入位置，将链接插入到bolckquote最后一个元素节点(p)的内部
			//获得quotelist[i]的所有元素节点
			var quoteChildren = quotelist[i].getElementsByTagName("*");
			if(quoteChildren.length > 0){
				var elem = quoteChildren[quoteChildren.length - 1];
				alert(elem.nodeType);
				//创建链接
				var link = document.createElement("a");
				var link_text = document.createTextNode("source");
				link.appendChild(link_text);
				link.setAttribute("href", url);
				//插入链接
				elem.appendChild(link);
			}
		}
	}
}

function addLoadEvent(func){
	var oldonload = window.onload;
	if(typeof window.onload != "function"){
		window.onload = func;
	}else{
		window.onload = function(){
			oldonload();
			func();
		}
	}
}

addLoadEvent(displayAbbrs);
addLoadEvent(displayCitations);
