/*操作步骤
1. 从第7条开始，除了最后一条，全部隐藏
2. 点击“显示全部品牌”时，做以下操作
	1. 将隐藏的内容全部显示
	2. “显示全部品牌”变为“显示精简品牌”
	3. 推荐品牌高亮展示
3. 点击“显示精简品牌”，做以下操作
	1. 从第7条开始，除了最后一条，全部隐藏
	2. “显示精简品牌”变为“显示全部品牌”
	3. 去掉推荐品牌的高亮
*/
$(function(){
	//从第7条开始，除了最后一条，全部隐藏
	var $category = $("ul li:gt(5):not(:last)");
	$category.hide();
	//点击“显示全部品牌”时
	var $btn = $(".showmore > a");
	$btn.click(function(){
		if($category.is(":visible")){//如果已全部展示
			//从第7条开始，除了最后一条，全部隐藏
			$category.hide();
			//“显示全部品牌”变为“显示精简品牌”
			$(this).find("span").text("显示全部品牌");
			//推荐品牌取消高亮展示
			$("ul li").removeClass("promoted");
		}else{
			//将隐藏的内容全部显示
			$category.show();
			//“显示全部品牌”变为“显示精简品牌”
			$(this).find("span").text("显示精简品牌");
			//推荐品牌高亮展示
			$("ul li").filter(":contains('brand 2'),:contains('brand 5'),:contains('brand 9')").addClass("promoted");
		}
		//链接不跳转
		return false;
	});	
});