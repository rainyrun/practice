package controller;


import java.util.Date;

import org.springframework.beans.factory.annotation.*;
import org.springframework.stereotype.*;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import domain.PageModel;
import domain.Student;
import service.StudentService;

@Controller
public class StuManager {
	@Autowired
	@Qualifier("stuService")
	private StudentService stuService;
	
	@RequestMapping("/test")
	public String test() {
		
		return "test";
	}
	
	@RequestMapping("/index")
	public String queryStu(String queryByName, String queryBySex, Integer currentPage, Model model) {
		// 处理参数
		if(queryBySex != null && (queryBySex.equals("--请选择--") || queryBySex.equals("")))
			queryBySex = null;
		if(currentPage == null)
			currentPage = 1;
		if(queryByName != null && queryByName.equals(""))
			queryByName = null;
		// 查询结果
		PageModel pageModel = stuService.query(queryByName, queryBySex, currentPage);
		// 放入模型
		model.addAttribute("pageModel", pageModel);
		// 回显数据
		model.addAttribute("queryByName", queryByName);
		model.addAttribute("queryBySex", queryBySex);
		// 跳转到index.jsp
		return "index";
	}
	
	@RequestMapping("/toAddStu")
	public String toAddStu() {
		return "addStu";
	}
	@RequestMapping("/addStu")
	public String addStu(Student stu) {
		// 设置学生创建日期
		stu.setCreate_time(new Date());
		stuService.add(stu);
		return "redirect:/index";
	}

	@RequestMapping("/deleteStu")
	public String deleteStu(String sid) {
		System.out.println(sid);
		stuService.delete(sid);
		// 注1
		return "test";
	}
	
	@RequestMapping("/toUpdate")
	public String toUpdate(int sid, Model model) {
		Student stu = stuService.queryById(sid);
		model.addAttribute("stu", stu);
		return "updateStu";
	}
	
	@RequestMapping("/updateStu")
	public String update(Student stu) {
		System.out.println(stu);
		stuService.update(stu);
		return "redirect:/index";
	}
}

/*
 * 注1：前端以ajax的方式请求，返回的视图不起作用。但是如果返回值是void，请求又会失败。原理不太懂。
 *
 */
