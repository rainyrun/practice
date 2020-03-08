package rainy.dao.impl;

import java.sql.SQLException;
import java.util.List;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import rainy.dao.CategoryDao;
import rainy.domain.Category;
import rainy.domain.Product;

public class CategoryDaoImpl implements CategoryDao {
	// 注1。DataSource
	private static ComboPooledDataSource ds = new ComboPooledDataSource();
	// QueryRunner
	private static QueryRunner runner = new QueryRunner(ds);

	@Override
	public List<Category> queryCategories() {
		// sql语句
		String sqlCategories = "select * from category;";
		List<Category> categories = null;
		try {
			// 查询结果
			categories = runner.query(sqlCategories, new BeanListHandler<Category>(Category.class));
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return categories;
	}

	@Override
	public List<Product> queryProductsByCategory(String cid, int startIndex, int recordNum) {
		// sql语句
		String sqlProductsByCategory = "select * from product where cid = ? limit ?,?;";
		List<Product> prods = null;
		try {
			// 查询结果
			Object[] params = {cid, startIndex, recordNum};
			prods = runner.query(sqlProductsByCategory, new BeanListHandler<Product>(Product.class), params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return prods;
	}

	@Override
	public int queryCategoryRecords(String cid) {
		// sql语句
		String sqlCategoryRecords = "select count(*) from product where cid=?";
		Long records = 0L;
		try {
			records = (Long) runner.query(sqlCategoryRecords, new ScalarHandler(), cid);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return records.intValue();
	}

	@Override
	public void add(Category cate) {
		String sqlAdd = "insert into category values(?, ?);";
		Object[] params = {cate.getCid(), cate.getCname()};
		try {
			runner.update(sqlAdd, params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void update(Category cate) {
		String sqlUpdate = "update category set cname = ? where cid = ?;";
		Object[] params = {cate.getCname(), cate.getCid()};
		try {
			runner.update(sqlUpdate, params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void delete(String cid) {
		String sqlDelete = "delete from category where cid = ?;";
		try {
			runner.update(sqlDelete, cid);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}

/* 
 * 注1: 之前忘了添加static关键字，导致每个对象都生成一个链接，数据库报“链接太多”的异常。
 */
