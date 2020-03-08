/*实现自定义的超链接提示
1. 鼠标移上链接时，显示title里的提示
2. 鼠标离开链接时，取消提示
*/
$(function(){
	$("a.tooltip").mouseover(function(e){
		//取消默认提示
		this.myTitle = this.title;
		this.title = "";
		//新建div
		// var tooltip = "<div id='tooltip'>"+this.myTitle+"</div>";
		var tooltip = "<div id='tooltip'><img src='"+this.href+"' alt='预览图片' /></div>";
		//追加到文档
		$("body").append(tooltip);
		var x = 10;
		var y = 20;
		$("#tooltip")
			.css({
				"top": (e.pageY+y) + "px",
				"left": (e.pageX+x) + "px"
			}).show("fast");//设置xy坐标并立即显示
	})
	.mouseout(function(){
		//恢复默认提示
		this.title = this.myTitle;
		//取消提示
		$("#tooltip").remove();
	})
	.mousemove(function(e){
		$("#tooltip")
			.css({
				"top": (e.pageY+y) + "px",
				"left": (e.pageX+x) + "px"
			});
	});
});