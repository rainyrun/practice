package service.impl;

import java.util.List;

import domain.PageModel;
import domain.Student;
import mapper.StudentDao;
import service.StudentService;

public class StudentServiceImpl implements StudentService {
	private StudentDao stuDao;
	private PageModel pageModel;

	@Override
	public PageModel query(String queryByName, String queryBySex, int currentPage) {
		// 查询总记录数
		int total = stuDao.queryTotalRecords(queryByName, queryBySex);
		// 配置pageModel
		pageModel.setCurrentPage(currentPage);
		pageModel.setTotalRecords(total);
		pageModel.setPageSize(5);
		StringBuffer url = new StringBuffer("index?");
		if(queryByName != null)
			url.append("&queryByName=" + queryByName);
		if(queryBySex != null)
			url.append("&queryBySex=" + queryBySex);
		pageModel.setUrl(url.toString());
		// 查询学生信息列表
		List<Student> records = stuDao.query(queryByName, queryBySex, pageModel.getStartIndex(), pageModel.getPageSize());
		pageModel.setRecords(records);
		// 返回pageModel
		return pageModel;
	}

	public StudentDao getStuDao() {
		return stuDao;
	}

	public void setStuDao(StudentDao stuDao) {
		this.stuDao = stuDao;
	}

	public PageModel getPageModel() {
		return pageModel;
	}

	public void setPageModel(PageModel pageModel) {
		this.pageModel = pageModel;
	}

	@Override
	public void add(Student stu) {
		stuDao.add(stu);		
	}

	@Override
	public void delete(String sid) {
		stuDao.delete(sid);
	}

	@Override
	public Student queryById(int sid) {
		return stuDao.queryById(sid);
	}

	@Override
	public void update(Student stu) {
		stuDao.update(stu);
	}
}
