import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { ExamService } from '../exam.service';
import { ExaminationAdd } from 'src/models/examinationAdd';
import { Observable } from 'rxjs';
import { Examination } from 'src/models/examination';

@Component({
  selector: 'app-ecp',
  templateUrl: './ecp.component.html',
  styleUrls: ['./ecp.component.css']
})
export class EcpComponent {

  titleInput!: string;
  firstExaminerInput!: string;
  secondExaminerInput!: string;
  thirdExaminerInput!: string;

  createdExam$!: Observable<Examination>;

  constructor(private router: Router, private examService: ExamService) {}

  onSubmit() {
    let status = 0;
    if (this.titleInput == undefined || this.firstExaminerInput == undefined || this.secondExaminerInput == undefined || this.thirdExaminerInput == undefined) {
      status = -1;
    }
    if (this.firstExaminerInput === this.secondExaminerInput || this.firstExaminerInput === this.thirdExaminerInput || this.secondExaminerInput === this.thirdExaminerInput) {
      status = -1;
    }
    if (status == 0) {
      // this.examService.testLiveness().subscribe(
      //   (data) => {
      //     console.log(JSON.stringify(data))
      //   }
      // );
      let id = 0;
      
      this.examService.addExaminer(this.firstExaminerInput).subscribe(
        () => {
          console.log("added first one");
        }
      );
      this.examService.addExaminer(this.secondExaminerInput).subscribe(
        () => {
          console.log("added second one");
        }
      );
      this.examService.addExaminer(this.thirdExaminerInput).subscribe(
        () => {
          console.log("added third one");
        }
      );
      this.examService.addExamination(this.titleInput, this.firstExaminerInput, this.secondExaminerInput, this.thirdExaminerInput).subscribe(
        (examination: Examination) => {
          this.router.navigateByUrl("/examination/dashboard/" + examination.id);
        }
      );
  
    
    } else {
      window.alert("Form is not valid");
    }
  }

}
