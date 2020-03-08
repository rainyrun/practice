$(function(){
	// 文档加载完成时，从服务器获取热门商品
	var url = "/demoShoppingMall/ProductServlet?method=hotProducts";
	$.get(url, function(data){
		// 遍历获取到到的json数组
		$(data).each(function(index, obj){
			// 插入商品的逻辑区域
			$("#hotProducts").append("<div class='col-md-3 text-center' id='" + obj.pid + "'></div>");
			// 插入图片
			$("#" + obj.pid).append("<img alt='"+ obj.pname +"' src='/demoShoppingMall/" + obj.pimage_short + "' width='200' height='200' /><br />");
			// 插入商品名
			$("#" + obj.pid).append("<a href='/demoShoppingMall/ProductServlet?method=productByPid&pid=" + obj.pid + "'>" + obj.pname + "</a>")
			// 插入商品价格
			$("#" + obj.pid).append("<p>" + obj.shop_price + "</p>");
		});
	}, "json");
});