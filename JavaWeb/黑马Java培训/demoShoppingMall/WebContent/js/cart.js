$(function(){
	// 当修改购物车中的商品数量时
	$("#num").change(function(){
		// 将商品数量、商品pid传给服务器
		var url = "/demoShoppingMall/CartServlet";
		var method = "modifyProduct";
		var num = $(this).val();
		var pid = $(this).attr("pid");
		$.post(url,{method:method, num:num, pid:pid}, function(){
			// 跳转到购物车页面
			window.location.href = "/demoShoppingMall/jsp/cart.jsp";
		});
	});
	
	// 当点击“删除”按钮时
	$(".deleteFromCart").click(function(){
		if(confirm("确认删除？")){
			var url = "/demoShoppingMall/CartServlet";
			var method = "deleteFromCart";
			var pid = $(this).attr("pid");
			$.post(url, {method:method, pid:pid}, function(){
				// 刷新购物车页面
				window.location.href = "/demoShoppingMall/CartServlet?method=toCart";
			});
		}
	});
	
	// 当点击“提交订单”按钮时
	$("#toOrder").click(function(){
		// 跳转到OrderServlet处理
		window.location.href = "/demoShoppingMall/OrderServlet?method=toOrder";
	});
});