$(function(){
	// 找到“加入购物车”按钮
	$("#addToCart").click(function(){
		// 找到表单元素
		var formObj = document.getElementById("addToCartForm");
		formObj.method = "post";//是否可行？
		formObj.action = "/demoShoppingMall/CartServlet?method=addToCart";
		formObj.submit();
	})
});