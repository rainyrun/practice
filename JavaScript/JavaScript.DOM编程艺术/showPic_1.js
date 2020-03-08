/*功能：将需要预览的图片，展示在预览区域
  参数：
  whichpic：需要预览的图片元素
*/
function showPic(whichpic){	
	//获得图片链接地址、title属性
	var source = whichpic.getAttribute("href");
	var text = whichpic.getAttribute("title");
	//获取预览区域的元素
	var placeHolder = document.getElementById("placeHolder");
	//修改预览区域的展示图片
	placeHolder.setAttribute("src", source);
	//获取文字描述元素
	var description = document.getElementById("description");
	//修改文字区域的内容
	description.firstChild.nodeValue = text;
}