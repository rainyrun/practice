// 页面加载完成时，请求分类数据
$(function(){
	var url = "/demoShoppingMall/CategoryServlet";
	var method = "categories";
	$.post(url, {"method":method}, function(data){
		// 处理返回的JSON数据
		$.each(data, function(index, obj){
			$("#categories").append("<li><a href='/demoShoppingMall/CategoryServlet?method=productsByCategory&cid=" + obj.cid + "'>" + obj.cname + "</li>");
		});
	}, "json");
});