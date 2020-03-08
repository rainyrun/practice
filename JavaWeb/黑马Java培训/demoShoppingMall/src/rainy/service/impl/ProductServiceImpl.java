package rainy.service.impl;

import java.util.List;

import rainy.dao.ProductDao;
import rainy.dao.impl.ProductDaoImpl;
import rainy.domain.PageModel;
import rainy.domain.Product;
import rainy.service.ProductService;

public class ProductServiceImpl implements ProductService {
	
	private static ProductDao prodDao = new ProductDaoImpl();

	@Override
	public List<Product> getHotProducts() {
		return prodDao.queryHotProducts();
	}

	@Override
	public Product getProductByPid(String pid) {
		return prodDao.queryProductByPid(pid);
	}

	@Override
	public PageModel getProductsByPage(int currentPage) {
		// 获取商品总数
		int records = prodDao.queryProductRecords();
		if (records == 0)// 没有商品
			return null;
		// 创建pageModel对象
		PageModel pageModel = new PageModel(currentPage, records);
		// 设置每页有多少条数据
		pageModel.setPageSize(10);
		// 获取当页的数据
		List<Product> products = prodDao.queryProductsByPage(pageModel.getStartIndex(), pageModel.getPageSize());
		pageModel.setRecords(products);
		pageModel.setUrl("AdminProductServlet?method=getProducts");
		return pageModel;
	}

	@Override
	public void updateProduct(Product prod) {
		prodDao.update(prod);
	}

	@Override
	public void addProduct(Product prod) {
		prodDao.add(prod);
	}

}
