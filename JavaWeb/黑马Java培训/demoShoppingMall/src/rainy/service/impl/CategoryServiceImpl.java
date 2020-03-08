package rainy.service.impl;

import java.util.List;

import rainy.dao.CategoryDao;
import rainy.dao.impl.CategoryDaoImpl;
import rainy.domain.Category;
import rainy.domain.PageModel;
import rainy.domain.Product;
import rainy.service.CategoryService;

public class CategoryServiceImpl implements CategoryService {
	private static CategoryDao categoryDao = new CategoryDaoImpl();

	@Override
	public List<Category> getCategories() {
		return categoryDao.queryCategories();
	}

	@Override
	public PageModel getProductsByCategory(String cid, int currentPage) {
		// 查询分类下商品个数
		int totalRecords = categoryDao.queryCategoryRecords(cid);
		// 创建PageModel
		PageModel pageModel = new PageModel(currentPage, totalRecords);
		// 配置PageModel
		pageModel.setRecords(categoryDao.queryProductsByCategory(cid, pageModel.getStartIndex(), pageModel.getPageSize()));
		pageModel.setUrl("CategoryServlet?method=productsByCategory&cid=" + cid);// 分页按钮上的部分链接
		return pageModel;
	}

	@Override
	public void addCategory(Category cate) {
		categoryDao.add(cate);
	}

	@Override
	public void updateCategory(Category cate) {
		categoryDao.update(cate);
	}

	@Override
	public boolean deleteCategory(String cid) {
		int result = categoryDao.queryCategoryRecords(cid);
		// 分类下有商品，无法删除
		if (result != 0)
			return false;
		categoryDao.delete(cid);
		return true;
	}

}
